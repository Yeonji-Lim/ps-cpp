-- 131124
-- 리뷰를 가장 많이 작성한 회원의 리뷰들
-- 회원 이름, 리뷰 텍스트, 리뷰 작성일이 출력
-- 리뷰 작성일을 기준으로 오름차순, 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순
WITH NEW (MID, RCOUNT) AS (
    SELECT M.MEMBER_ID, COUNT(*)
    FROM MEMBER_PROFILE M
        JOIN REST_REVIEW R
        ON M.MEMBER_ID=R.MEMBER_ID
    GROUP BY M.MEMBER_ID
)

SELECT M.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM MEMBER_PROFILE M
        JOIN REST_REVIEW R
        ON M.MEMBER_ID=R.MEMBER_ID
WHERE M.MEMBER_ID IN (
    SELECT MID
    FROM NEW
    WHERE RCOUNT = (
        SELECT MAX(RCOUNT)
        FROM NEW
    )
)
ORDER BY R.REVIEW_DATE, R.REVIEW_TEXT
