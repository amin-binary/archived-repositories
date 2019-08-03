import chart_wasm_builder from './chart-wasm.js'

const chart_wasm = chart_wasm_builder({ onRuntimeInitialized: () => run(chart_wasm) });
window.cw = chart_wasm;

function run({
    OhlcBuffer
}) {
    const buffer = new OhlcBuffer();
    buffer.data_resize(3);
    buffer.print();
    console.warn(buffer.data_u32view());
    buffer.delete();
}

// import OhlcBuffer from '../dist/chart-wasm'
// import App from './app';
// import ohlc_glsl from './ohlc.glsl'; 

// const app = new App({canvas_id: 'webgl-canvas'});

// const program = app.build_program(ohlc_glsl);

// window.app = app;
// window.program = program;

// const gl = app.gl;

// /**
//  * @param {WebGLRenderingContext} gl
//  * @param {WebGLProgram} program
//  */
// function setup(gl, program) {
//     gl.clearColor(1, 1, 1, 1);
//     gl.useProgram(program);

//     const buffer = gl.createBuffer();
//     gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
//     gl.vertexAttribPointer(0, 2, gl.FLOAT, false, 4 * 2, 0);
//     gl.enableVertexAttribArray(0);
// }

// const timestamp = +new Date();
// const data = [ ];
// for(var i = 0; i < 30  ; ++i) {
//     data.push({
//         open: Math.random() * 1 + 2,
//         high: 4,
//         low: 1,
//         close: Math.random() * 2 + 2.5,
//         timestamp: timestamp + i*1000
//     });
// }

// const buffer = new OhlcBuffer();
// buffer.setData(data);
// window.b = buffer;

// // let uLimitsLocation =  gl.getUniformLocation(program, 'uLimits');

// /**
//  * @param {WebGLRenderingContext} gl
//  * @param {WebGLProgram} program
//  */
// function draw(gl) {
//     buffer.animate((+new Date()%4000) > 1000 ? 50 : -50);
//     buffer.recaculate_vbuf();
//     const positions = buffer.vbuf_f32view();

//     gl.bufferData(gl.ARRAY_BUFFER, positions, gl.DYNAMIC_DRAW);
//     gl.clear(gl.COLOR_BUFFER_BIT);
//     gl.drawArrays(gl.TRIANGLES, 0, positions.length/2);
//     requestAnimationFrame(() => draw(gl));
// }

// setup(gl, program);
// draw(gl);

// window.gl = gl;
// window.draw = () => draw(gl);

