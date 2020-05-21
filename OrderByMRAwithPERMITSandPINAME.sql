SELECT MRA_ID AS ID, MRA_TITLE AS Title, MRA_LINK AS Link,PERMIT_ID AS PERMIT, PI_NAME AS Investigator
FROM MRA AS M, Permit AS P, PI as I
WHERE M.STUDY_ID = P.STUDY_ID
AND P.PI_ID = I.PI_ID
ORDER BY M.MRA_ID
