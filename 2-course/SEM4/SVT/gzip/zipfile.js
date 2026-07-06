const fs = require('fs');
const path = require('path');

const sourceFile = path.join(process.cwd(), 'large-file.txt');
const outputFile = path.join(process.cwd(), 'large-file.zip');

if (!fs.existsSync(sourceFile)) {
  console.error(`Source file not found: ${sourceFile}`);
  process.exit(1);
}

async function main() {
  const { ZipArchive } = await import('archiver');
  const output = fs.createWriteStream(outputFile);
  const archive = new ZipArchive({
    zlib: { level: 9 },
  });

  output.on('close', () => {
    console.log(`Archive created: ${outputFile}`);
    console.log(`Size: ${archive.pointer()} bytes`);
  });

  archive.on('warning', (error) => {
    if (error.code === 'ENOENT') {
      console.warn(error.message);
      return;
    }

    throw error;
  });

  archive.on('error', (error) => {
    throw error;
  });

  archive.pipe(output);
  archive.file(sourceFile, { name: 'large-file.txt' });
  await archive.finalize();
}

main().catch((error) => {
  console.error(error);
  process.exit(1);
});
