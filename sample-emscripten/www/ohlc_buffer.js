import {
    OhlcBuffer as OhlcBufferRust,
} from '../pkg/chart_wasm';
import {memory} from '../pkg/chart_wasm_bg';

window.mm = memory;

class OhlcBuffer extends OhlcBufferRust {
    constructor() {
        super();
        Object.assign(this, OhlcBufferRust.new());
    }

    /**
    * example:
    * buffer.setData([{ open: 3.0, high: 5.0, low: 2, close: 4.0, timestamp: +new Date() }]);
    */
    setData(array){
        if (!Array.isArray(array)) {
            throw new Error("Invalid input type, expected Array");
        }
        const length = array.length;

        this.data_resize(length);

        const f32view = this.data_f32view();
        const u32view = this.data_u32view();

        for(let idx = 0; idx < length; ++idx) {
            const { open, high, low, close, timestamp } = array[idx];
            const offset = idx * 6;

            f32view[offset + 0] = open;
            f32view[offset + 1] = high
            f32view[offset + 2] = low
            f32view[offset + 3] = close
            u32view[offset + 4] = timestamp |0;
            u32view[offset + 5] = timestamp / 4294967296;
        }
    }

    cloneData() {
        const length = this.length();

        const f32view = this.data_f32view();
        const u32view = this.data_u32view();

        const array = [];
        for(let idx = 0; idx < length; ++idx) {
            const offset = idx * 6;

            array.push({
                open     : f32view[offset + 0],
                high     : f32view[offset + 1],
                low      : f32view[offset + 2],
                close    : f32view[offset + 3],
                timestamp: u32view[offset + 4] +  4294967296 * u32view[offset + 5],
            });
        }
        return array;
    }
}

// ----------------------- tests --------------------------------------------

window.test1 = function test_OhldBuffer() {
    const buffer = new OhlcBuffer();
    const data = [
        {open: 2, high: 4, low: 1, close: 3, timestamp: +new Date()},
        {open: 3, high: 5, low: 2, close: 4, timestamp: +new Date()},
    ];
    buffer.setData(data);
    buffer.print();
    const cloned_data = buffer.cloneData();
    buffer.free();
    console.warn('passed : ' ,JSON.stringify(data) === JSON.stringify(cloned_data));
}
test1();

window.test2 = function test_calc_vbuf() {
    const buffer = new OhlcBuffer();
    const data = [
        {open: 2, high: 4, low: 1, close: 3, timestamp: +new Date()},
        {open: 3, high: 5, low: 2, close: 4, timestamp: +new Date() + 1000},
        {open: 3, high: 5, low: 2, close: 4, timestamp: +new Date() + 2000},
    ];
    buffer.setData(data);
    buffer.print();
    buffer.recaculate_vbuf();
    const vbuf_f32view = buffer.vbuf_f32view();
    console.warn('passed : ' , vbuf_f32view.length === 36);
    buffer.free();
}
test2();

export default OhlcBuffer;
