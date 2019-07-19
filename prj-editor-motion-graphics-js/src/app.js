import React, {Component} from 'react';
import {render} from 'react-dom';
import {observable, action} from 'mobx';
import {observer, inject} from 'mobx-react';
import uid from './util/uid.js';
import {Page, PageModel} from './page.js';
import './style/app.scss';

export
class AppModel {
    @uid id;
    /** @type {PageModel[]} */
    @observable pages = [];

    constructor() {
        this.pages.push(new PageModel());
    }
};

const app = (
    /** @type {AppModel} */ model
) => {
    console.warn(model);
    return (
        <div className='app'>
            {model.pages.map(
                page => <Page key={page.id} model={page} />
            )}
        </div>
    );
}


/** @type {import('mobx-react').IReactComponent} */ 
export
const App = inject(({app}) => app)(observer(app));

