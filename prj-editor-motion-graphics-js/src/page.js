import React, {Component} from 'react';
import {render} from 'react-dom';
import {observable, action} from 'mobx';
import {observer, inject} from 'mobx-react';
import uid from './util/uid.js';
import './style/page.scss';

export
class PageModel {
    @uid id;
    @observable artboards = [];
};
const page = (
    { /** @type {PageModel} */ model}
) => (
    <div className='page'>
    </div>
);

export
const Page = observer(page);

