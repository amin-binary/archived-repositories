import React, {Component} from "react";
import {mapper} from './view_model.js';
import './scss/block.scss';
import {logTransform} from './math.js';

const transformer = logTransform({ min: 2, max: 50 });

const Block = ({utxs}) => (
    <div className='block'>
        <svg viewBox='0 0 100 100' className='circle-icon'>
            <circle cx="50" cy="50" r={transformer(utxs.length)} fill="green" />
        </svg>
        hello {utxs.length}!
    </div>
);

export default idx => mapper(
  ({utxs}) => ({
    utxs
  }),
    Block
);
