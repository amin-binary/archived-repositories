import React, { Component } from "react";
import ReactDOM from "react-dom";
import {reg_txns} from './api.js';
import {add_utx} from './view_model.js';
import CBlocks from "./c_blocks.jsx";

reg_txns({
  on_utx: add_utx,
});

const app = document.getElementById("app");
ReactDOM.render(<CBlocks />, app);
