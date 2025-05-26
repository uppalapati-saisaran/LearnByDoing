from models.database import get_connection 

def create_ticket(title,description,customer_id):
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute('''
                       INSERT INTO tickets (title,description,customer_id) VALUES(?,?,?)
                       ''', (title,description,customer_id))
        conn.commit() 

def list_tickets():
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute('''
                       SELECT t.id, t.title, t.status, t.created_at,c.name FROM tickets t JOIN customers c ON t.customer_id = c.id
                       ''')
        return cursor.fetchall() 
    
def update_ticket_status(ticket_id, status):
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute("UPDATE tickets SET status = ? WHERE id = ?",(status,ticket_id)) 
        conn.commit() 



        