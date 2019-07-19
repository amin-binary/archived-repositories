import React from 'react';
import {render} from 'react-dom';
import {observable, action} from 'mobx';
import {observer, Provider} from 'mobx-react';
import {App, AppModel} from './App.js';

const appModel = new AppModel();
window['app'] = appModel;

setTimeout(
    () => render(
        <Provider app={appModel}>
            <App />
        </Provider>,
        document.getElementById('editor-app'),
    )
);


