var faker = require('faker');

var getAddress = () => { return [faker.fake("{{address.streetAddress}} {{address.streetName}}"), faker.fake("{{address.city}}"), faker.fake("{{address.stateAbbr}}"), faker.fake("{{address.zipCode}}").split('-')[0]]; }

const numRecords = 100;

console.log(`ID\tStreet\tCity\tState\tZip`);
for (var i = 0; i < numRecords; i++) {
    var random = getAddress();
    console.log(`${i}\t${random[0]}\t${random[1]}\t${random[2]}\t${random[3]}`);

}