var faker = require('faker');
const delimiter = ","
const numRecords = process.argv[2];
const numAddresses = process.argv[3];
const oldestLetterYears = 2/12;// 2 months
const types = [
    "priority",
    "normal",
    "economy"
];
console.log(`Mail ID${delimiter}From Address ID${delimiter}To Address ID${delimiter}Date Sent${delimiter}Type`);

for (var i = 0; i < numRecords; i++) {
    var from = Math.floor(Math.random() * numAddresses);
    var to = Math.floor(Math.random() * numAddresses);
    while (to == from) {
        to = Math.floor(Math.random() * numAddresses);
    }
    var sent = faker.date.past(oldestLetterYears);
    console.log(`${i}${delimiter}${from}${delimiter}${to}${delimiter}${sent.getMonth()+1}/${sent.getDay()+1}/${sent.getFullYear()}${delimiter}${types[Math.floor(Math.random() * types.length)]}`);

}