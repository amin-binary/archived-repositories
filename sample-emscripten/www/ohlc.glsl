#vertex shader

attribute vec4 aPosition;
// uniform vec4 uLimits;
void main() {
  // gl_Position = vec4(aPosition.xyz, uLimits.w+1.0);
  gl_Position = aPosition;
}




#fragment shader

precision mediump float;
void main() {
  gl_FragColor = vec4( 0.0, 1.0, 1.0, 1.0 );
}
