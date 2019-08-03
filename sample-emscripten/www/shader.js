
/**
 * @param {WebGLRenderingContext} gl
 * @param {number} type - shader type
 * @param {string} source - shader source
 */
function load_shader(gl, type, source) {

    const shader = gl.createShader(type);
    if(!shader) { return 0; }

    gl.shaderSource(shader, source);
    gl.compileShader(shader);

    const compiled = gl.getShaderParameter(shader, gl.COMPILE_STATUS);
    if(!compiled) {
        const log_message = gl.getShaderInfoLog(shader);
        console.warn(log_message);

        gl.deleteShader(shader);
        return 0;
    }
    return shader;
}

/**
 * @param {WebGLRenderingContext} gl
 * @param {WebGLShader} v_shader - vertex shader
 * @param {WebGLShader} f_shader - fragment shader
 */
function link_shaders(gl, v_shader, f_shader) {
    const program = gl.createProgram();
    if(!program)  { return 0; }

    gl.attachShader(program, v_shader);
    gl.attachShader(program, f_shader);

    gl.linkProgram(program);
    const linked = gl.getProgramParameter(program, gl.LINK_STATUS);
    if(!linked) {
        const log_message = gl.getProgramInfoLog(program);
        console.warn(log_message);
        gl.deleteProgram(program);
        return 0;
    }
    gl.deleteShader(v_shader);
    gl.deleteShader(f_shader);
    return program;
}

export {
    load_shader,
    link_shaders,
};
