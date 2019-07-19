const fs      = require('fs').promises;
const fetch   = require('node-fetch');
const cheerio = require('cheerio');
const Epub    = require('epub-gen');


function PromiseProcessor({max}) {
    let _running = 0;
    const callbacks = [];

    function launch_more() {
        while(_running < max && callbacks.length) {
            const cb = callbacks.shift();
            ++_running;
            cb().then(cb.resolve)
               .catch((e) => {
                console.error;
            }).then(() => {
                --_running;
                launch_more();
            });
        }
    }

    return {
        push: cb => {
            callbacks.push(cb);
            return new Promise((res) => {
                cb.resolve = res;
                launch_more();
            });
        },
        get running() {
            return _running;
        }
    }
};


function App() {
    const requested = { };
    const url = 'https://www.postgresql.org/docs/11/static/';

    async function get_page(href) {
        requested[href] = true;
        const html = await fetch(url + href).then(r => r.text());
        const $    = cheerio.load(html);
        return $;
    };

    const processor = PromiseProcessor({max: 15});
    const seen = { };
    let idx = 0;

    async function get_href({href, process_links}) {
        let $ = seen[href];
        if(!$) {
            $ = seen[href] = await get_page(href);
            console.warn(++idx + ':   ' + href);
        }


        const next_href = $('a[accesskey=n]').attr('href');
        if(process_links) {
            const requests = $('a').each((_, a) => {
                const $a = $(a);
                let nhref = $a.attr('href');

                nhref = nhref && nhref.split('#')[0];

                if(!nhref || nhref.startsWith('/') || nhref.startsWith('http') || !nhref.endsWith('.html'))
                    return;

                $a.attr('href', nhref);

                if(requested[nhref])
                    return;

                requested[nhref] = true;
                processor.push(() => get_href({href: nhref, process_links: false}));
            });
        }
        return next_href;
    }

    async function run() {
        let href  = 'index.html';
        let cnt = 0;
        const pages = [];
		while(href !== 'bookindex.html') {
			const prev_href = href;
			href = await processor.push(() => get_href({href, process_links: true}));
			const $ = seen[prev_href];
			const $content = $('.navheader + div').attr('id', prev_href.split('.')[0]);
			const up_href  = $('.navheader a:contains("Up")').attr('href') || $('.navheader a:contains("Prev")').attr('href');
			let $title   = $content.find('.title').first();
			if(up_href) {
				$title = $title.replaceWith(`<a href="${up_href}">${$title.html()}</a>`);
			}

			console.warn(
				up_href,
				prev_href,
				$title.text(),
			);
			pages.push({
				title: $title.text(),
				data: $.html($content),
				filename: prev_href,
				beforeToc: true,
				// excludeFromToc: true,
			});
		}

        // let css = await fetch('https://www.postgresql.org/dyncss/base.css').then(r => r.text());;
        // css = `${css} body { padding: 0 10px; }`;

        const option = {
            title: "PostgreSQL", // *Required, title of the book.
            author: "postgre", // *Required, name of the author.
            publisher: "Postgresql.com", // optional
            cover: "./postgre-sql.png", // Url or File path, both ok.
            content: pages,
            appendChapterTitles: false,
			css: `pre { font-size: 0.85rem !important; }`
        };
        await new Epub(option, "./PostgreSQL.epub").promise;
    }

    return {run}
};

const app = App();
app.run();
