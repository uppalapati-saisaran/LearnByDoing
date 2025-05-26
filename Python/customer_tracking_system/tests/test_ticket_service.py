import unittest 
from models.database import setup_database 
from services import ticket_service

class TestTicketSystem(unittest.TestCase):
    def setUp(self):
        setup_database()
        self.name = "Test User"
        self.email = "test@example.com"
        self.title = "Sample Ticket"
        self.description = "Something went wrong."

    def test_create_ticket(self):
        ticket_service.create_new_tickets(self.name,self.email,self.title,self.description)
        tickets = ticket_service.get_all_tickets()
        self.assertTrue(any(self.title in t for t in tickets))

    def test_update_status(self):
        ticket_service.create_new_tickets(self.name,self.email,self.title,self.description)
        tickets = ticket_service.get_all_tickets()
        tid = tickets[-1][0]
        ticket_service.change_ticket_status(tid,"Closed")
        updated = ticket_service.get_all_tickets()[-1]
        self.assertEqual(updated[2],"Closed")

if __name__ == "__main__":
    unittest.main() 