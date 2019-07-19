import React from 'react'
import { connect } from 'react-redux'
import PieChart from './Pie.js'
import * as actions from '../actions/index.js'
import '!style!css!sass!../styles/graph.scss'

const Graph = ({title, passed, failed, code_covered, ok}) => {
  const state = ok ? 'green' : 'red';
  const tests_passed = (passed*100/(passed + failed) || 0).toFixed(0) + '%';
  const code_covered_color = code_covered < 50 ? '#7E310D' : '#2E4D1C';

  return <div className={`graph ${state}`}>
    <div className='title'>{title}</div>
    <div className='chart-container'>
      <div className='chart'>
        <PieChart slices={[ { color: '#74AC51', value: passed }, { color: '#EA7E41', value: failed } ]} />
      </div>
      <div className='tests-passed'>
        <span>{tests_passed}</span> <br/>
        <span>tests passed</span>
      </div>
    </div>
    <div className='progress'>
      <div className='done'  style={{flex: code_covered}} />
      <div className='remained' style={{flex: 100 - code_covered}} />
    </div>
    <div className='code-covered'>
      <span style={{color: code_covered_color}}>{code_covered + '%'}</span> <br/>
      <span>code covered</span>
    </div>
  </div>
};


export default connect(
  state => state
)(Graph);
