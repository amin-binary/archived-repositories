import React from 'react'
import { connect } from 'react-redux'
import { toggleTodo } from '../actions'
import ListItem from './ListItem'
import '!style!css!sass!../styles/list.scss';

const Header = () =>
  <ul className='list-header'>
    <li className='wide'>Changelist / Build </li>
    <li>Owner</li>
    <li className='wide'>Time Started</li>
    <li>State</li>
    <li>Metrics</li>
    <li>Build</li>
    <li>Unit Test</li>
    <li>Functional Test</li>
  </ul>

const List = ({items, active}) =>
  <div className='list'>
    <Header/>
    {items.map(item => <ListItem item={item} active={active} />)}
  </div>

export default connect(
  state => state,
)(List);
