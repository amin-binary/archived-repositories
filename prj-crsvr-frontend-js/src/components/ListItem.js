import React from 'react'
import { connect } from 'react-redux'
import * as actions from '../actions/index.js'
import Graph from './Graph.js'
import Metrics from './Metrics.js'
import Build from './Build.js'
import Result from './Result.js'

import _ from 'lodash'
import moment from 'moment'
import Isvg from 'react-inlinesvg'

import '!style!css!sass!../styles/list-item.scss'

const icons = {
  build: require('file!../assets/desktop-pc.svg'),
  firewall: require('file!../assets/firewall.svg')
}

const Progress = ({percent}) => {
  let state = {'0': 'pending', '100': 'complete', '-1': 'rejected'}[percent] || 'running';
  percent = percent !== -1 ? percent : 100;
  return <div className={`progress ${state}`}>
    <div className='active' style={{flex: percent}} />
    <div className='inactive' style={{flex: 100 - percent}} />
  </div>
}

const Header = ({info, progress, type}) => {
  const icon = type === 'firewall' ? icons.firewall : icons.build;
  const time = info.date && moment(info.date).format('M/DD/YYYY  h:ma')
  const state = info.state && _.capitalize(info.state);

  return <ul className='list-header'>
    <li className='wide'> <Isvg src={icon} /> <span className='name'>{info.name}</span> </li>
    <li> <span>{info.owner}</span> </li>
    <li className='wide'> <span>{time}</span> </li>
    <li> <span>{state}</span> </li>
    {progress.map(p =>
      <li> <Progress percent={p} /> </li>
    )}
  </ul>
}

let Detail = ({unit, functional, metrics, build, result, popup, showPopup, hidePopup}) => {
  const hide = e => { e.stopPropagation(); hidePopup(); };
  const cls = {
    metrics: popup === 'metrics' ? 'active' : '',
    build: popup === 'build' ? 'active' : '',
    unit: popup === 'unit' ? 'active' : '',
    functional: popup === 'functional' ? 'active' : '',
  }

  return <div className={`item-detail`}>
    <div className='box' onClick={() => showPopup('metrics')}>
      <Metrics {...metrics} />
      {popup === 'metrics' &&
        <div className='pop-over' onClick={hide}>
          <span> pop-over placehoder to be implemented.</span>
          <Metrics {...metrics} />
        </div>
      }
    </div>
    <div className='box' onClick={() => showPopup('build')}>
      <Build {...build} />
      {popup === 'build' &&
        <div className='pop-over' onClick={hide}>
          <span> pop-over placehoder to be implemented.</span>
          <Build {...build} />
        </div>
      }
    </div>
    <div className='box' onClick={() => showPopup('unit')}>
      <Graph {...unit}  title='Unit Test'/>
      {popup === 'unit' &&
        <div className='pop-over' onClick={hide}>
          <span> pop-over placehoder to be implemented.</span>
          <Graph {...unit}  title='Unit Test'/>
        </div>
      }
    </div>
    <div className='box' onClick={() => showPopup('functional')}>
      <Graph {...functional} title='Functional Test'/>
      {popup === 'functional' &&
        <div className='pop-over' onClick={hide}>
          <span> pop-over placehoder to be implemented.</span>
          <Graph {...functional} title='Functional Test'/>
        </div>
      }
    </div>
    <div className='result-box'> <Result {...result} /></div>
  </div>
}

Detail = connect(
  (state,props) => ({}),
  (dispatch, props) => ({
    showPopup: key => dispatch(actions.showPopup(props.id, key)),
    hidePopup: () => dispatch(actions.hidePopup(props.id))
  })
)(Detail);

const ListItem = ({onExpand, onCollapse, active, item}) => {
  const onClick =  active ? onCollapse : onExpand;
  const activeClass = active ? 'active' : '';

  return <div className={`list-item ${item.info.state} ${activeClass}`}>
      <div onClick={onClick}> <Header info={item.info} progress={item.progress} type={item.type} /> </div>
      <Detail {...item.detail} id={item.id} popup={item.popup}/>
      {/*{ active && <Detail {...item.detail}/>}*/}
  </div>
}


export default connect(
  (state, props) => ({
    active: props.active === props.item.id
  }),
  (dispatch, props) => ({
    onExpand: () => dispatch(actions.expandItem(props.item.id)),
    onCollapse: () => dispatch(actions.collapseItem(props.item.id))
  })
)(ListItem);
