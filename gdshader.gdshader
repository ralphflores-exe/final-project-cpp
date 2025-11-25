shader_type canvas_item;

uniform vec4 chroma_key_color : source_color = vec4(0.0, 1.0, 0.0, 1.0); // Default to green
uniform float fuzziness : hint_range(0.0, 1.0) = 0;
uniform float cutoff : hint_range(0.0, 1.0) = 0.95;

void fragment() {
    vec4 color = texture(TEXTURE, UV);
    // Calculate the difference between the current pixel color and the chroma key color
    float diff = distance(color.rgb, chroma_key_color.rgb);
    // Determine the alpha value based on the difference, using smoothstep for blending
    float alpha = smoothstep(cutoff - fuzziness, cutoff + fuzziness, diff);
    // Apply the new alpha value
    COLOR.a = alpha;
    // Keep the original color channels
    COLOR.rgb = color.rgb;
}
