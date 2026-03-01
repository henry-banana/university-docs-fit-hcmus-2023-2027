# Week Assignment: Table Management

## Overview

This week focuses on implementing the **Table Management** module for the Smart Restaurant system. You will build functionality that allows restaurant admins to manage tables, generate unique QR codes for each table, and handle QR code lifecycle operations.

---

## Learning Objectives

By the end of this assignment, you will be able to:
- Design and implement CRUD operations for table management
- Generate secure QR codes with signed tokens
- Implement QR code download/print functionality
- Handle QR code regeneration and invalidation
- Build a responsive admin interface for table management

---

## Prerequisites

- Completed authentication module (Admin login)
- Database setup with tables schema
- Basic understanding of JWT/token signing
- Familiarity with QR code generation libraries

---

## Feature Requirements

### 1. Table Management CRUD (0.5 points)

#### 1.1 Create Table
- **Fields:**
  - Table number/name (required, unique)
  - Capacity (number of seats, required)
  - Location/Zone (e.g., "Indoor", "Outdoor", "Patio", "VIP Room")
  - Status (Active/Inactive)
  - Description (optional)

- **Validation:**
  - Table number must be unique within the restaurant
  - Capacity must be a positive integer (1-20)
  - Location must be selected from predefined options or custom input

#### 1.2 View Tables
- Display all tables in a list/grid view
- Show table number, capacity, location, status, and QR code status
- Filter tables by:
  - Status (Active/Inactive)
  - Location/Zone
- Sort tables by:
  - Table number
  - Capacity
  - Creation date

#### 1.3 Edit Table
- Update table details (number, capacity, location, description)
- Change table status (Active/Inactive)
- Deactivating a table should:
  - Prevent new orders from being placed at that table
  - Not delete existing order history

#### 1.4 Deactivate/Reactivate Table
- Soft delete implementation (status change, not hard delete)
- Show confirmation dialog before deactivation
- Display warning if table has active orders

---

### 2. QR Code Generation (0.5 points)

#### 2.1 Generate Unique QR Code
- Each table must have a unique QR code
- QR code should encode a URL with signed token:
  ```
  https://restaurant-domain.com/menu?table={tableId}&token={signedToken}
  ```

#### 2.2 Signed Token Requirements
- Token should contain:
  - Table ID
  - Restaurant ID (for future multi-tenant support)
  - Timestamp (creation time)
  - Expiration (optional, for time-limited codes)
- Use JWT or HMAC for token signing
- Token should be verifiable on the backend

#### 2.3 QR Code Display
- Show QR code preview in admin panel
- Display associated table information alongside QR code
- Show token creation date and status

---

### 3. QR Code Download/Print (0.25 points)

#### 3.1 Download Options
- **PNG format:** High-resolution image suitable for digital use
- **PDF format:** Print-ready document with:
  - Restaurant logo (optional)
  - Table number prominently displayed
  - QR code centered
  - "Scan to Order" instruction text
  - WiFi information (optional)

#### 3.2 Batch Operations
- Download all QR codes as a ZIP file
- Generate a single PDF with all tables for bulk printing

#### 3.3 Print Preview
- In-browser print preview
- Customizable print layout (single QR per page or multiple)

---

### 4. QR Code Regeneration (0.25 points)

#### 4.1 Regenerate QR Code
- Generate new signed token for existing table
- Automatically invalidate old QR code/token
- Use cases:
  - QR code damaged or lost
  - Security concerns (old code leaked)
  - Periodic rotation policy

#### 4.2 Invalidation Handling
- Old tokens should return an error when scanned
- Display user-friendly message: "This QR code is no longer valid. Please ask staff for assistance."
- Log invalidated token attempts for security monitoring

#### 4.3 Bulk Regeneration
- Option to regenerate all QR codes at once
- Require admin confirmation for bulk operations
- Show summary of affected tables

---

## Technical Specifications (Suggested)

### Database Schema

```sql
CREATE TABLE tables (
    id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    table_number VARCHAR(50) NOT NULL,
    capacity INT NOT NULL CHECK (capacity > 0 AND capacity <= 20),
    location VARCHAR(100),
    description TEXT,
    status VARCHAR(20) DEFAULT 'active' CHECK (status IN ('active', 'inactive')),
    qr_token VARCHAR(500),
    qr_token_created_at TIMESTAMP,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    UNIQUE(table_number)
);

CREATE INDEX idx_tables_status ON tables(status);
CREATE INDEX idx_tables_location ON tables(location);
```

### API Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| GET | `/api/admin/tables` | Get all tables (with filters) |
| GET | `/api/admin/tables/:id` | Get single table details |
| POST | `/api/admin/tables` | Create new table |
| PUT | `/api/admin/tables/:id` | Update table |
| PATCH | `/api/admin/tables/:id/status` | Update table status |
| POST | `/api/admin/tables/:id/qr/generate` | Generate/Regenerate QR code |
| GET | `/api/admin/tables/:id/qr/download` | Download QR code (PNG/PDF) |
| GET | `/api/admin/tables/qr/download-all` | Download all QR codes |
| GET | `/api/menu` | Verify QR token and load menu |

### Suggested Libraries

**Backend (Node.js):**
- `qrcode` - QR code generation
- `jsonwebtoken` - JWT token signing
- `pdfkit` or `puppeteer` - PDF generation
- `archiver` - ZIP file creation

**Frontend (React):**
- `react-qr-code` - QR code display
- `file-saver` - File download handling
- `react-to-print` - Print functionality

---

## Deliverables

1. **Source Code**
   - Backend API implementation
   - Frontend components
   - Database migrations and seeds

2. **Documentation**
   - API documentation for table endpoints
   - QR token format specification

3. **Demo**
   - Working table management interface
   - QR code generation and download
   - Token verification flow

---

## Grading Criteria

| Criteria | Points | Description |
|----------|--------|-------------|
| Table CRUD Operations | 3 | Create, read, update, deactivate tables with proper validation |
| QR Code Generation | 3 | Unique QR codes with secure signed tokens |
| QR Download/Print | 2 | PNG and PDF download functionality |
| QR Regeneration | 1 | Regenerate QR and invalidate old codes |
| Public Hosting | 1 | Deploy feature to public hosting with accessible URL |
| **Total** | **10** | |

---

## Resources

- [QRCode.js Documentation](https://github.com/soldair/node-qrcode)
- [JWT.io - JSON Web Tokens](https://jwt.io/)
- [PDFKit Documentation](http://pdfkit.org/)
- [React QR Code](https://github.com/rosskhanas/react-qr-code)

---

## Tips

1. **Security First:** Always validate tokens on the backend. Never trust client-side token validation alone.

2. **User Experience:** Show loading states during QR generation and provide clear feedback on success/failure.

3. **Mobile Testing:** Test QR code scanning with actual mobile devices to ensure codes are readable.

4. **Error Handling:** Provide helpful error messages when invalid or expired QR codes are scanned.

5. **Performance:** Consider caching generated QR codes to avoid regenerating them on every request.