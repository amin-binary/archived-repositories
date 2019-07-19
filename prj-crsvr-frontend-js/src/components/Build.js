import React from 'react'
import Isvg from 'react-inlinesvg'
import moment from 'moment'
import '!style!css!sass!../styles/build.scss'

const icon = require('file!../assets/desktop-pc.svg');
const Build = ({date}) => {
  date = date && moment(date).format('h:ma - M/DD/YYYY');
  return <div className="build">
    <div className='title'>Build </div>
    <div className='icons'>
      <div>
        <div><Isvg src={icon} /></div>
        <span>Debug</span>
      </div>
      <div>
        <div><Isvg src={icon} /></div>
        <span>Release</span>
      </div>
    </div>
    <div className='footer'>
      {date}
    </div>
  </div>
};

export default Build;
