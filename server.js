const express = require('express');
const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

// Serial port configuration
const port = new SerialPort('COM3', { baudRate: 9600 }); 
// Replace with the actual serial port name
const parser = port.pipe(new Readline({ delimiter: '\r\n' }));

// Web server configuration
const app = express();
const server = app.listen(3000, () => {
  console.log('Server listening on port 3000');
});

// Serve static files
app.use(express.static('public'));

// Serial port data event listener
parser.on('data', (data) => {
  console.log(`Received data from Arduino: ${data}`);
});

// Handle POST request with slider value
app.post('/slider', express.json(), (req, res) => {
  const { value } = req.body;
  console.log(`Slider value received: ${value}`);
  port.write(value + '\n');
  res.sendStatus(200);
});
