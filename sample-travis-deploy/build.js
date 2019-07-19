const fs = require('fs');

const name = process.env.TRAVIS_BRANCH;
let dir = './dist';
if (!fs.existsSync(dir)){ fs.mkdirSync(dir); }
if(name === 'dev')  {
    dir += '/beta';
    if (!fs.existsSync(dir)){ fs.mkdirSync(dir); }
}


fs.writeFileSync(`${dir}/index.html`, `hello from ${name}: ${(new Date()).toString()}`, 'utf-8');

