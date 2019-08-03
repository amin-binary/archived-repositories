module.exports = function(source) {

    let [vshader, fshader] = source.split('#fragment shader');
    vshader = vshader.replace('#vertex shader', '').trim();
    fshader = fshader.trim();

return `export default {
  vertex_shader: \`${vshader}\`,
  fragment_shader: \`${fshader}\`
}`;
}
