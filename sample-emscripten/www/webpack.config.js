const CopyWebpackPlugin = require("copy-webpack-plugin");
const path = require('path');

module.exports = {
    entry: "./index.js",
    output: {
        path: path.resolve(__dirname, "dist"),
        filename: "bootstrap.js",
    },
    mode: "development",
    plugins: [
        new CopyWebpackPlugin(['index.html'])
    ],
    module: {
        rules: [{
            test: /\.glsl/,
            use: [{ loader: path.resolve('./glsl-loader.js') }]
        }]
    }
};
