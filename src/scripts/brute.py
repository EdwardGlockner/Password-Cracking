import hashlib
from urllib.request import urlopen

def readwordlist(url):
    """


    """
    try:
        word_list = urlopen(url).read()
    except Exception as e:
        print(f"Could not reading the wordlist: {url}. Error: {e}")
        exit()
    return word_list

def hash(password):
    """

    """
    return hashlib.sha1(password.encode()).hexdigest()


def bruteforce(password_list, real_password):
    """

    """
    for guess_password in password_list:
        if hash(guess_password) =)=
