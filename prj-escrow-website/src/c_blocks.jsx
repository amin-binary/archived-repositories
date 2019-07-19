import React, {Component} from "react";
import {mapper} from './view_model.js';
import Block from './block.jsx';
import './scss/c_blocks.scss';



const CBlocks = ({blocks}) => (
    <div className='c-blocks'>
        {
            blocks.map((_, idx) => {
                const B = Block(idx);
                return <B key={idx}/>
            })
        }
    </div>
);

export default mapper(
    ({utxs, blocks}) => ({
        count: utxs.length,
        blocks
    }),
    CBlocks
);
