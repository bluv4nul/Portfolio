const fs = require('fs');
const path = require('path');
const { once } = require('events');

const FILE_SIZE = 2 * 1024 * 1024 * 1024; // 2 GiB
const CHUNK_SIZE = 1024 * 1024; // 1 MiB
const CHARS = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
const outputFile = path.join(process.cwd(), 'large-file.txt');

function createChunk(size) {
  const buffer = Buffer.allocUnsafe(size);

  for (let i = 0; i < size; i += 1) {
    buffer[i] = CHARS.charCodeAt(i % CHARS.length);
  }

  return buffer;
}

async function main() {
  const stream = fs.createWriteStream(outputFile);
  const chunk = createChunk(CHUNK_SIZE);

  let written = 0;

  try {
    while (written < FILE_SIZE) {
      const remaining = FILE_SIZE - written;
      const data = remaining >= CHUNK_SIZE ? chunk : chunk.subarray(0, remaining);

      if (!stream.write(data)) {
        await once(stream, 'drain');
      }

      written += data.length;
    }

    stream.end();
    await once(stream, 'finish');

    console.log(`File created: ${outputFile}`);
    console.log(`Size: ${written} bytes`);
  } catch (error) {
    stream.destroy();
    throw error;
  }
}

main().catch((error) => {
  console.error(error);
  process.exit(1);
});
