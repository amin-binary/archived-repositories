## Rules

-   Get the task done at all costs, use time conservatively.
-   Don't use 3rd party packages unless necessary.
-   Don't write tests unless it's absolutely needed.
-   Leave short inline comments if you have to.

## TODO:

please add items as you go.

#### /daemon

-   [x] `daemon-manager.js` : responsible for running and interaction with a service.
-   [ ] `binance.js`
    -   [x] subscribe to [binance](https://www.binance.com).
    -   [ ] stream the data to redis.
-   [ ] `bitfinix.js`
    -   [ ] subscribe to [bitfinix](https://www.bitfinex.com/)
    -   [ ] stream the data to redis
-   [ ] `redis.js` : runs a redis server with persistence configurations.

#### /lib

-   [ ] `redis-client.js` : redis client used by other services

#### /wallet

-   [ ] `bitcoin.js` : run a bitcoin wallet using [bitcoinjs-lib](https://github.com/bitcoinjs/bitcoinjs-lib)
-   [ ] `ethereum.js` : run an eth wallet

#### /scripts

-   [ ] `install-deps.sh` : install dependencies
    -   [ ] [watchman](https://facebook.github.io/watchman/)
    -   [ ] [nodejs](https://nodejs.org/en/)
    -   [ ] [redis](https://redis.io/)
-   [ ] `restart.sh <service-name>` : restart one or more services (used by watch.sh).
-   [ ] `watch.sh` : watch for file changes and restart services.
-   [ ] `test.sh <service-name>` : run tests for one or more services.
