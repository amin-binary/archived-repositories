/* As the name implies, this is only to show that UI is updateable.
We are updating state with random data intervally. */

const r = n => Math.floor(Math.random() * n) + 1;
const rr = (f,t) => r(t-f+1)+f-1;

function getResultText(result) {
  if(result.state === 'pending') return 'Pending';
  if(result.state === 'complete') return 'Complete';
  if(result.state === 'merged') return 'Auto-Merged';
  if(!result.unit_ok) return 'Unit-Test Failing';
  if(!result.functional_ok) return 'Functional Failing';
  if(!result.metrics_ok) return 'Metrics Reduction';
  return '-';
}
const generate = {
  detail: (item_state) => ({
    unit: {
      passed: r(2000),
      failed: r(200),
      code_covered: r(100),
      get ok() {
        return this.failed <= this.passed;
      }
    },
    functional: {
      passed: r(1000),
      failed: r(500),
      code_covered: r(100),
      get ok() {
        return this.failed <= this.passed;
      }
    },
    build: {
      date: new Date(2014, 3, r(30), r(24), r(60))
    },
    metrics: {
      test: r(120) - 20,
      maintain: r(20),
      security: r(120) - 20,
      workmanship: r(120) - 20,
      get ok() {
        return this.test >= 0 && this.maintain >= 0;
      }
    },
    _inx: r(2) -1,
    get result() {
      return {
        state: item_state === 'pending' ? 'pending' : (this.unit.ok && this.functional.ok && this.metrics.ok) ? ['complete', 'merged'][this._inx] : 'rejected',
        unit_ok: this.unit.ok,
        functional_ok: this.functional.ok,
        metrics_ok: this.metrics_ok,
        get text() { return getResultText(this); }
      }
    }
  })
};

let state = {
  active: -1, // no item is initially active
  items: [
    {
      id: 1,
      type: 'firewall',
      info: {
        name: 'Tenrox-R1-1235',
        state: 'pending'
      },
      progress: [0, 0, 0, 0],
      detail: generate.detail('pending')
    },
    {
      id: 2,
      type: 'build',
      info: {
        name: '432462',
        state: 'running',
        owner: 'jtuck',
        date: new Date(2014, 3, 18, 12, 12, 0)
      },
      progress: [65, 0, 0, 0],
      detail: generate.detail('running')
    },
    {
      id: 3,
      type: 'build',
      info: {
        name: '432461',
        state: 'rejected',
        owner: 'samy',
        date: new Date(2014, 3, 18, 10, 53, 0)
      },
      progress: [-1, 100, 100, 100],
      detail: {
        unit: {
          passed: 142,
          failed: 30,
          code_covered: 76,
          ok: false
        },
        functional: {
          passed: 4321,
          failed: 2345,
          code_covered: 23,
          ok: true
        },
        build: {
          date: new Date(2014, 3, 17, 10, 46)
        },
        metrics: {
          test: 64,
          maintain: -53,
          security: 64,
          workmanship: 72,
          ok: false
        },
        result: {
          state: 'rejected',
          text: 'Metrics Reduction'
        }
      }
    },
    {
      id: 4,
      type: 'firewall',
      info: {
        name: 'Tenrox-R1-1234',
        state: 'complete',
        date: new Date(2014, 3, 17, 9, 42, 0)
      },
      progress: [100, 100, 100, 100],
      detail: generate.detail('complete')
    },
  ]
};

function updateItem(item) {
  const detail = item.detail;
  const {metrics, unit, functional, build} = detail;
  const ret = {
    ...item,
    detail: {
      ...detail,
      metrics: {
        ...metrics,
        test: Math.min(metrics.test + rr(-3,3),99),
        maintain: Math.min(metrics.maintain + rr(-2,1),99),
        security: Math.min(metrics.security + rr(-2,2),99),
        workmanship: Math.min(metrics.workmanship + rr(-3,3),99)
      },
      unit: {
        ...unit,
        // passed: Math.max(unit.passed + rr(-3,3),0),
        failed: Math.max(unit.failed + rr(-5,5), 0),
        code_covered: Math.max(Math.min(unit.code_covered + rr(-1,1), 100), 0)
      },
      functional: {
        ...functional,
        // passed: Math.max(unit.passed + rr(-3,3),0),
        failed: Math.max(functional.failed + rr(-5,5), 0),
        code_covered: Math.max(Math.min(functional.code_covered + rr(-1,1), 100), 0)
      }
    }
  };
  return ret;
}

function updateProgress(item) {
  const prog = item.progress;
  let nprog = prog.map(p => p); // take a copy.

  let state = item.info.state;
  if(item.info.state === 'running') {
    let sum = 0;
    for(let i = 0; i < prog.length; ++i) {
      sum += prog[i];
      if(prog[i] >= 0 && prog[i] < 100){
        nprog[i] = prog[i] + 1;
        break;
      }
    }
    if(sum == 400)
      state = 'complete';
  }

  return {
    ...item,
    progress: nprog,
    info: {
      ...item.info,
      state: state
    }
  };
}

function updateState() {
  return {
    active: state.active,
    items: state.items.map(item => {
      if(item.info.state === 'pending') return item;
      if(item.id !== state.active) return updateProgress(item);
      return updateItem(updateProgress(item));
    })
  };
}

/* random update stae every 1 second */
setInterval(() => {
  cb && cb(updateState());
}, 500);

/* add new item every 30 seconds */
function addItem() {
  const id = Math.max(...state.items.map(item => item.id)) + 1;
  const type = ['firewall', 'build'][rr(0,1)];
  const name = type == 'build' ? (432460+id+'') : 'Tenrox-R' + id;

  const new_item = {
    id: id,
    type: type,
    info: {
      name: name,
      state: 'pending'
    },
    progress: [0, 0, 0, 0],
    detail: generate.detail('pending')
  };

  const new_state = {
    ...state,
    items: [ ...state.items.map(item => {
        if(item.info.state !== 'pending') return item;
        const result = {
          ...item.detail.result,
          state: (item.detail.unit.ok && item.detail.functional.ok && item.detail.metrics.ok) ? ['complete', 'merged'][rr(0,1)] : 'rejected',
        };
        return {
          ...item,
          info: { ...item.info, state: 'running'},
          detail: {
            ...item.detail,
            result: {
              ...result,
              text: getResultText(result)
            }
          }
        }
      }),
      new_item
    ]
  };
  cb && cb(new_state);
  time_out += 40*1000;
  setTimeout(addItem, time_out);
};

let time_out = 20*1000;
setTimeout(addItem, time_out);

let cb = undefined;

export default {
  get_state: () => state,
  onUpdate: _cb => (cb = _cb),
  update: _state => { state = _state; }
};
