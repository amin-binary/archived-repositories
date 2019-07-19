ko.punches.enableAll();

function set_values(json) {
    console.warn(json);
    return axios.post('https://api.keyvalue.xyz/05cf7837/amnrst/' + json);
}
function get_values() {
    return axios.get('https://api.keyvalue.xyz/05cf7837/amnrst');
}

const dice = () => Math.floor(Math.random() * (6)) + 1;

const defaults = {
    pos: [
        '',
        'bb', '', '', '', '', 'wwwww',
        '', 'www', '' , '',  '', 'bbbbb',
        'wwwww', '', '', '' , 'bbb', '',
        'bbbbb', '', '', '', '', 'ww',
        ''
    ],
    spidx: -1,
    status: 'white:'
};

const reset = () => {
    return set_values(JSON.stringify(defaults)).then(() =>  location.reload());
};

let fo = false;

function ViewModel() {
    this.status = ko.observable('loading ...');
    this.pos = ko.observableArray(defaults.pos);

    this.spidx = ko.observable(defaults.spidx);

    this.save = function() {
        const data = JSON.stringify({ pos: this.pos(), spidx:this.spidx(), status: this.status() });
        return set_values(data).then(() => {
            fo = false;
        });
    }
    this.update = function(data) {
        console.warn(data);
        this.pos(data.pos);
        this.spidx(data.spidx);
        this.status(data.status);
    }
    this.status_clk = function() {
        const x = dice(), y = dice();
        const status = this.status();
        if(status === 'white:') {
            fo = true; this.status(`white: ${x}, ${y}`);
        }
        else if(status.startsWith('white:')) {
            fo = true; this.status(`black:`);
        }
        else if(status === 'black:') {
            fo = true; this.status(`black: ${x}, ${y}`);
        }
        else if(status.startsWith('black:')) {
            fo = true; this.status(`white:`);
        }
        else { alert('hey you!'); }

        this.save();
    }
    this.p_clk = function(pidx) {
        const pos = this.pos();
        if(this.spidx() == -1) {
            fo = true;
            this.spidx(pidx);
            this.save();
            return;
        }
        if(this.spidx() == pidx) {
            fo = true;
            this.spidx(-1);
            this.save();
            return;
        }

        const from = this.spidx();
        const to = pidx;
        const ch = pos[from][pos[from].length-1];
        pos[from] = pos[from].slice(0, pos[from].length - 1);

        if(pos[to] && ch !== pos[to][pos[to].length-1]) {
            if(pos[to].length == 1) {
                const idx = pos[to] == 'w' ? 0 : 25;
                pos[idx] += pos[to];
                pos[to] = '';
            }
            else if(confirm("Reset?")) {
                reset();
                return;
            }
        }
        pos[to] += ch;
        this.pos(pos);
        this.spidx(-1);

        this.save();
    }

    this.sections = ko.computed(function() {
        const pos = this.pos();
        const spidx = this.spidx();
        const mapper = (data, n) => data.map((d, idx) => ({
            data: d,
            idx: idx+n,
            selected: idx+n == spidx ? 'selected' : ''
        }));
        return [
            {cls: 'tl', items: mapper(pos.slice(0, 7), 0)},
            {cls: 'tr', items: mapper(pos.slice(7, 13), 7)},
            {cls: 'bl', items: mapper(pos.slice(19, 26), 19).reverse()},
            {cls: 'br', items: mapper(pos.slice(13, 19), 13).reverse()},
        ];
    }, this);
};

ko.applyBindings(window.vm = new ViewModel());

setInterval(() => {
    get_values().then(data => {
        if(fo) { return; }
        vm.update(data.data);
    });
}, 500);

