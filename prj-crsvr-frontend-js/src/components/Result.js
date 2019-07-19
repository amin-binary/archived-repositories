import React from 'react'
import { connect } from 'react-redux'
import * as actions from '../actions/index.js'
import '!style!css!sass!../styles/result.scss'

const Result = ({state, text, notify}) => {
  let small = '';
  if(state === 'merged') { small = 'Change Accepted'; }
  if(state === 'rejected') { small = 'Change Rejected'; }

  const btn = {complete: 'Deploy', merged: 'Merged Build', rejected: 'Find Issues' }[state];

  return <div className="result">
    <div className='title'>Result:</div>
    <div className={`label ${state}`}>
      <span className='small'>{small}</span>
      <span className='big'>{text}</span>
    </div>
    <div className='footer'>
      {state !== 'pending' && <button className={state} onClick={notify}>{btn}</button>}
      {state === 'complete' && <span> to: <br/></span>}
      {state === 'complete' && <select value="development" >
        <option value="development" selected="selected">Development</option>
        <option value="production">Production</option>
        <option value="gh-pages">Gh-Pages</option>
      </select>}
    </div>
  </div>
};

export default connect(
  state => ({}),
  dispatch => ({
    notify: () => dispatch(actions.notify('Not Implemented'))
  })
)(Result);
