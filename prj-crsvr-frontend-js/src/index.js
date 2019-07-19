import React from 'react'
import { render } from 'react-dom'
import { Provider } from 'react-redux'
import { createStore } from 'redux'
import reducer from './reducers'
import List from './components/List'
import server from './reducers/fake-server.js'
import * as actions from './actions'

import '!style!css!sass!./styles/index.scss';
let store = createStore(reducer);
store.subscribe(() => server.update(store.getState()));
server.onUpdate(new_state => store.dispatch(actions.serverUpdate(new_state)));

render(
  <Provider store={store}>
    <div className='container'>
      <List />
    </div>
  </Provider>,
  document.getElementById('root')
)
