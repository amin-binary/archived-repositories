import React, {Component} from 'react';
import {render} from 'react-dom';
import {observable, action} from 'mobx';
import {observer} from 'mobx-react';
import './style/artboard.scss';

class ArtboardModel {
};

@observer 
class Artboard extends Component {
    model = new ArtboardModel();

    render() {
        const m = this.model;
        return (
            <div className='artboard'>
            </div>
        )
    }
};

export default Artboard; 
