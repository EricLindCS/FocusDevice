
const express = require('express');
const SerialPort = require('serialport').ReadlineParser;

const app = express();
const port = 3000;

const arduinoPort = new SerialPort({
    path: 'COM3',
    baudRate: 9600,
});

app.use(express.static(path.join(__dirname, 'public')));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

app.get('/send/:value', (req, res) => {
  const value = parseInt(req.params.value);

  if (Number.isNaN(value)) {
    res.status(400).send('Invalid value');
    return;
  }

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












