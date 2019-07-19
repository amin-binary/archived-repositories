import { combineReducers } from 'redux'
import { createReducer } from 'redux-act'
import * as actions from '../actions/index.js'
import server from './fake-server.js'


const reducer = createReducer({
  [actions.expandItem]: (state, id) => ({
    ...state,
    active: id,
  }),
  [actions.collapseItem]: state => ({
    ...state,
     active: -1
   }),
  [actions.hidePopup]: (state, data) => ({
      active: state.active,
      items: state.items.map(item => ({ ...item, popup: '' }))
  }),
  [actions.showPopup]: (state, data) => ({
      active: state.active,
      items: state.items.map(item => ({ ...item, popup: (item.id === data.id) ? data.key : '' }))
  }),
  [actions.notify]: (state, text) => {
    alert(text);
    return state;
  },
  [actions.serverUpdate]: (state, new_state) => new_state
}, server.get_state());

export default reducer;
