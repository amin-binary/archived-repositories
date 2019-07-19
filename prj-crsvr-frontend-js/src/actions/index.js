import { createAction } from 'redux-act'

/* some arrow functions are just added to explain what the payload of each action is. */
export const expandItem = createAction('expand a list item', id => id);
export const collapseItem = createAction('expand a list item');
export const showPopup = createAction('show pop-up dialog', (id, key) => ({id,key}));
export const hidePopup = createAction('hide pop-up dialog', id => id);
export const notify = createAction('notify', text => text);
export const serverUpdate = createAction('update from fake server', state => state);
