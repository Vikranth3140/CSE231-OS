script_name = Q3.sh

input_file = input.txt

run: $(script_name) $(input_file)
	chmod +x $(script_name)
	./$(script_name) < $(input_file)

.PHONY: clean

clean:
	rm -f $(script_name)