.PHONY: all


all: address mail

NUM_ADDRESS=100
NUM_MAIL=100

clean: 
	rm out/* || echo ""

# Runners
address:
	node address.js $(NUM_ADDRESS) > out/address.txt

mail: 
	node mail.js $(NUM_MAIL) $(NUM_ADDRESS) > out/mail.txt

