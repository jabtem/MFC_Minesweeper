#pragma once
class CMyButton : public CButton  //CMyButton  =>derive from the CButton.
{
    // Construction
public:
    CMyButton();

    // Attributes
public:

    // Operations
public:

    // Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CMyButton)
        //}}AFX_VIRTUAL

    // Implementation
public:
    virtual ~CMyButton();

    // Generated message map functions
protected:
    //{{AFX_MSG(CMyButton)
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};


