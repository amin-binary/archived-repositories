const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin')
const MiniCssExtractPlugin = require("mini-css-extract-plugin");

const devMode = process.env.WEBPACK_SERVE;

module.exports = {
    entry: './src/index.js',
    mode: devMode ? 'development' : 'production',
    devtool: 'eval-source-map',
    output: {
        path: __dirname + '/dist',
        filename: 'index.js'
    },
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ['@babel/preset-env', '@babel/preset-react'],
                        "plugins": [
                            ["@babel/plugin-proposal-decorators", { "legacy": true }],
                            ["@babel/plugin-proposal-class-properties", { "loose" : true }]
                        ]
                    }
                }
            },
            {
                test: /\.(sa|sc|c)ss$/,
                use: [
                    devMode ? 'style-loader' : MiniCssExtractPlugin.loader,
                    'css-loader',
                    'sass-loader',
                ],
            }
        ]
    },
    optimization: {
        splitChunks: {
            chunks: 'all',
        },
        runtimeChunk: true,
    },
    plugins: [
        new MiniCssExtractPlugin({
            filename: devMode ? '[name].css' : '[name].[hash].css',
            chunkFilename: devMode ? '[id].css' : '[id].[hash].css',
        }),
        new HtmlWebpackPlugin({
            template: 'src/index.html'
        })
    ],
    serve: {
        port: 8080,
        clipboard: true,
    },
}
