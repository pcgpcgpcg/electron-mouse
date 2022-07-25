//var mousecur = require('bindings')('mousecur.node')

// mousecur.ShowMouseCursor(false);

// console.log('after setNullCursor');

//console.log('This should be eight:', addon.add(3, 5))
if (process.platform !== 'win32') {
    throw new Error('Only works on windows.')
  } else {
    const mousecur = require('bindings')('mousecur.node')
    module.exports = mousecur
  }