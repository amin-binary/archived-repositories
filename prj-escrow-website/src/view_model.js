import { observable, action, configure } from 'mobx';
import { inject, observer } from 'mobx-react';

configure({
  enforceActions: 'always',
});

class ViewModel {
    @observable ws_state = 'connecting';
    @observable utxs = []; // unconfirmed transactions
    @observable blocks = [0,1,2];
}

// global state object.
const VM = new ViewModel();

export // similar to redux connect.
const mapper = (map, comp) => inject(() => map(VM))(observer(comp));


/*************** actions *******************/
export
const add_utx = action(utx => VM.utxs.push(utx));


