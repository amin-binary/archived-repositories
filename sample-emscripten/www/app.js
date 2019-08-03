import {link_shaders, load_shader} from './shader';
class App {
    constructor({canvas_id}) {
        this.canvas = document.getElementById(canvas_id);
        this.canvas.style.width = '100%';
        this.canvas.style.height = '100%';

        /** @type WebGLRenderingContext */
        this.gl = this.canvas.getContext('webgl');

        this.refresh_canvas_size = this.refresh_canvas_size.bind(this);
        window.addEventListener('resize', this.refresh_canvas_size);
        this.refresh_canvas_size();
    }

    refresh_canvas_size() {
        const rect = this.canvas.getBoundingClientRect();

        this.canvas.width = rect.width;
        this.canvas.height = rect.height;

        this.gl.viewport(
            0,
            0,
            this.gl.drawingBufferWidth,
            this.gl.drawingBufferHeight
        );
    }

    free() {
        window.removeEventListener('resize', this.canvas_refresh_size);
        this.gl = null;
        this.canvas = null;
    }

    build_program({vertex_shader, fragment_shader}) {
        const gl = this.gl;
        return link_shaders(
            gl,
            load_shader(gl, gl.VERTEX_SHADER, vertex_shader),
            load_shader(gl, gl.FRAGMENT_SHADER, fragment_shader)
        );
    }
}


export default App;
