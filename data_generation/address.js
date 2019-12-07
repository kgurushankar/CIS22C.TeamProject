var faker = require('faker');
const delimiter = ","

var getAddress = () => { return [faker.fake("{{address.streetAddress}} {{address.streetName}}"), faker.fake("{{address.city}}"), faker.fake("{{address.stateAbbr}}"), faker.fake("{{address.zipCode}}").split('-')[0]]; }

const numRecords = process.argv[2];

console.log(`ID${delimiter}Street${delimiter}City${delimiter}State${delimiter}Zip`);
for (var i = 0; i < numRecords; i++) {
    var random = getAddress();
    console.log(`${i}${delimiter}${random[0]}${delimiter}${random[1]}${delimiter}${random[2]}${delimiter}${random[3]}`);

}