var faker = require('faker');

const numRecords = 100;
const numAddresses = 100;
const oldestLetterYears = 2/12;
const types = [
    "priority",
    "normal",
    "economy"
];
console.log(`Mail ID\tFrom Address ID\tTo Address ID\tDate Sent\tType`);

for (var i = 0; i < numRecords; i++) {
    var from = Math.floor(Math.random() * numAddresses);
    var to = Math.floor(Math.random() * numAddresses);
    while (to == from) {
        to = Math.floor(Math.random() * numAddresses);
    }
    var sent = faker.date.past(oldestLetterYears);
    console.log(`${i}\t${from}\t${to}\t${sent.getMonth()}/${sent.getDay()}/${sent.getFullYear()}\t${types[Math.floor(Math.random() * types.length)]}`);

}