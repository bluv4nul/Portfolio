import { Server } from 'node:https';
import { readFileSync } from 'node:fs';

const certificate_dir = "C:/Users/andre/certificate/" 

Server({
 key: readFileSync(certificate_dir + 'server.key'),cert: readFileSync(certificate_dir + 'server.crt')
 }, (req, res) => {
 res.end('hello world');
})
.listen(8000, () => console.log('Server running on https://localhost:8000'));