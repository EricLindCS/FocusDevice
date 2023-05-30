const express = require('express');
const app = express();
const port = 3000; // Change the port number if needed

// Serve the HTML file
app.use(express.static('public'));

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
