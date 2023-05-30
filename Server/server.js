

const express = require('express');
const SerialPort = require('serialport').ReadlineParser;

const app = express();
const port = 3000;

const arduinoPort = new SerialPort({
    path: 'COM3',
    baudRate: 9600,
});

app.get('/', (req, res) => {
  res.send('Web Interface');
});

app.get('/send/:value', (req, res) => {
  const value = parseInt(req.params.value);

  // Send the value to the Arduino over the serial connection
  arduinoPort.write(value.toString(), (err) => {
    if (err) {
      console.error('Error sending data:', err);
      res.status(500).send('Error sending data');
    } else {
      console.log('Data sent:', value);
      res.send('Data sent');
    }
  });
});

app.listen(port, () => {
  console.log(`Server listening on port ${port}`);
});
