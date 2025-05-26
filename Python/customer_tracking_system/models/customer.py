from models.database import get_connection

def add_customer(name,email):
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute("INSERT INTO customers(name, email) VALUES(?,?)",(name,email))
        conn.commit()
        return cursor.lastrowid 
    
def get_customer_by_email(email):
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM customers WHERE email = ?", (email,))
        return cursor.fetchone() 
    

