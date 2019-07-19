import React from 'react'
import '!style!css!sass!../styles/metrics.scss'

const Metrics = ({test, maintain, security, workmanship, ok}) => {
  const state = ok ? 'green' : 'red';
  const dir = {
    test: test >= 0 ? 'top' : 'bottom',
    maintain: maintain >= 0 ? 'top' : 'bottom',
    security: security >= 0 ? 'right' : 'left',
    workmanship: workmanship >= 0 ? 'right' : 'left'
  };

  return <div className={`metrics ${state}`}>
    <div className='title'>Metrics </div>
    <div className='arrows'>
      <div>
        <div className={dir.test}>{Math.abs(test)}</div>
        <span>Test</span>
      </div>
      <div>
        <div className={dir.maintain}>{Math.abs(maintain)}</div>
        <span>Maintainablity</span>
      </div>
      <div>
        <div className={dir.security}>{Math.abs(security)}</div>
        <span>Security</span>
      </div>
      <div>
        <div className={dir.workmanship}>{Math.abs(workmanship)}</div>
        <span>Workmanship</span>
      </div>
    </div>
  </div>
};

export default Metrics;
