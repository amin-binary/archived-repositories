export const logTransform = ({ min, max }) => len => {
    const res = (Math.log(len)/Math.log(2000.0)) * max;
    return Math.min(+max, Math.max(+min, res));
};