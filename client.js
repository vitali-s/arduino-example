const SerialPort = require('serialport')
const fs = require('fs');

const port = new SerialPort('COM4', {
  baudRate: 9600
});

port.on('data', function (data) {
    var values = Buffer.from(data, 'hex').toString('utf8')

    if (values) {
      fs.appendFileSync('data.csv', new Date().toISOString().replace(/T/, ' ').replace(/\..+/, '') + "," + values);
    }
})

