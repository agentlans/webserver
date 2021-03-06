from base import *

MAGIC = "Allow From test"

CONF = """
vserver!1!rule!730!match = directory
vserver!1!rule!730!match!directory = /allow1
vserver!1!rule!730!match!final = 0
vserver!1!rule!730!allow_from = 99.99.99.99
"""


class Test (TestBase):
    def __init__ (self):
        TestBase.__init__ (self, __file__)
        self.name              = "Allow from test, forbidden"
        self.request           = "GET /allow1/file HTTP/1.0\r\n"
        self.expected_error    = 403
        self.forbidden_content = MAGIC
        self.conf              = CONF

    def Prepare (self, www):
        self.Mkdir (www, "allow1")
        self.WriteFile (www, "allow1/file", 0o444, MAGIC)

