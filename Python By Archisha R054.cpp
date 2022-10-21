import random
import array as arr

# maximum length of password needed
# this can be changed to suit your password length
list_A= [8,9,10,11,12]
MAX_LEN = random.choice(list_A)

# declare arrays of the character that we need in out password
# Represented as chars to enable easy string concatenation
print("Enter Your name: ")
name= input()
nameU= name.upper()
nameL= name.lower()

print("Enter Your Age: ")
age= input()

CHARS_U= list(nameU)
CHARS_L= list(nameL)
CHARS_NO= list(age)

DIGITS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

SYMBOLS = ['@', '#', '$', '%', '=', ':', '?', '.', '/', '|', '~', '>', '*', '(', ')', '<']

# combines all the character arrays above to form one array
COMBINED_LIST = DIGITS + CHARS_U + CHARS_L + SYMBOLS + CHARS_NO

# randomly select at least one character from each character set above
rand_digit = random.choice(DIGITS)
rand_CHARS_U= random.choice(CHARS_U)
rand_CHARS_L= random.choice(CHARS_L)
rand_CHARS_NO= random.choice(CHARS_NO)
rand_symbol = random.choice(SYMBOLS)

# combine the character randomly selected above
# at this stage, the password contains only 4 characters but
# we want a 8 to 12 character password
temp_pass = rand_digit + rand_CHARS_U + rand_CHARS_L + rand_symbol + rand_CHARS_NO


# now that we are sure we have at least one character from each
# set of characters, we fill the rest of
# the password length by selecting randomly from the combined
# list of character above.
for x in range(MAX_LEN - 5):
	temp_pass = temp_pass + random.choice(COMBINED_LIST)

	# convert temporary password into array and shuffle to
	# prevent it from having a consistent pattern
	# where the beginning of the password is predictable
	temp_pass_list = arr.array('u', temp_pass)
	random.shuffle(temp_pass_list)

# traverse the temporary password array and append the chars
# to form the password
password = ""
for x in temp_pass_list:
		password = password + x
		
# print out password
print("The Generated password is: " , password)